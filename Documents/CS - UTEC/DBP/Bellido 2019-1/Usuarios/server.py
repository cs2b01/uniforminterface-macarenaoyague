from flask import Flask,render_template, request, session, Response, redirect
from database import connector
from model import entities
import json

db = connector.Manager()
engine = db.createEngine()

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/usuarios')
def users():
    db_session = db.getSession(engine)
    users = db_session.query(entities.Usuarios)
    data = users[:]
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype = 'application/json')

@app.route('/create_test_users', methods = ['GET'])
def create_test_users():
    db_session = db.getSession(engine)
    usuario = entities.Usuarios(codigo="201710481", nombre="Macarena", apellido="Oyague", password="hola123")
    db_session.add(usuario)
    db_session.commit()
    return "Test Usuario creado!"

if __name__ == '__main__':
    app.secret_key = ".."
    app.run(port=8080, threaded=True, host=('0.0.0.0'))
