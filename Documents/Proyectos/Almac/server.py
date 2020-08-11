from flask import Flask,render_template, request, session, Response, redirect
from database import connector
from model import entities
import json
import time
from operator import itemgetter, attrgetter

db = connector.Manager()
engine = db.createEngine()

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/static/<content>')
def static_content(content):
    return render_template(content)



@app.route('/categories', methods = ['GET'])
def get_categories():
    session = db.getSession(engine)
    dbResponse = session.query(entities.Category)
    data = []
    for category in dbResponse:
        data.append(category)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')


@app.route('/categories', methods = ['POST'])
def create_category():
    c =  json.loads(request.form['values'])
    category = entities.Category(
        name=c['name']
    )
    session = db.getSession(engine)
    session.add(category)
    session.commit()
    return 'Created Category'


@app.route('/categories', methods = ['PUT'])
def update_category():
    session = db.getSession(engine)
    id = request.form['key']
    category = session.query(entities.Category).filter(entities.Category.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(category, key, c[key])
    session.add(category)
    session.commit()
    return 'Updated Category'

@app.route('/categories', methods = ['DELETE'])
def delete_category():
    id = request.form['key']
    session = db.getSession(engine)
    categories = session.query(entities.Category).filter(entities.Category.id == id)
    for category in categories:
        session.delete(category)
    session.commit()
    return "Deleted Category"

if __name__ == '__main__':
    app.secret_key = ".."
    app.run(port=8080, threaded=True, host=('127.0.0.1'))
