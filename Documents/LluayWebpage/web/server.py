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

@app.route('/static/<content>')
def static_content(content):
    return render_template(content)


@app.route('/users', methods = ['GET'])
def get_users():
    session = db.getSession(engine)
    dbResponse = session.query(entities.User)
    data = []
    for user in dbResponse:
        data.append(user)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')


@app.route('/users/<id>', methods = ['GET'])
def get_user(id):
    db_session = db.getSession(engine)
    users = db_session.query(entities.User).filter(entities.User.id == id)
    for user in users:
        js = json.dumps(user, cls=connector.AlchemyEncoder)
        return  Response(js, status=200, mimetype='application/json')

    message = { 'status': 404, 'message': 'Not Found'}
    return Response(message, status=404, mimetype='application/json')

@app.route('/users', methods = ['POST'])
def create_user():
    c =  json.loads(request.form['values'])
    user = entities.User(
        username=c['username'],
        name=c['name'],
        fullname=c['fullname'],
        password=c['password']
    )
    session = db.getSession(engine)
    session.add(user)
    session.commit()
    return 'Created User'

@app.route('/users', methods = ['PUT'])
def update_user():
    session = db.getSession(engine)
    id = request.form['key']
    user = session.query(entities.User).filter(entities.User.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(user, key, c[key])
    session.add(user)
    session.commit()
    return 'Updated User'

@app.route('/users', methods = ['DELETE'])
def delete_message():
    id = request.form['key']
    session = db.getSession(engine)
    messages = session.query(entities.User).filter(entities.User.id == id)
    for message in messages:
        session.delete(message)
    session.commit()
    return "Deleted Message"

# [ C R U D     C A T E G O R I E S]

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

# [ C R U D     C O U N T R I E S]

@app.route('/countries', methods = ['GET'])
def get_countries():
    session = db.getSession(engine)
    dbResponse = session.query(entities.Country)
    data = []
    for country in dbResponse:
        data.append(country)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')

@app.route('/countries', methods = ['POST'])
def create_country():
    c =  json.loads(request.form['values'])
    country = entities.Country(
        name=c['name']
    )
    session = db.getSession(engine)
    session.add(country)
    session.commit()
    return 'Created Country'

@app.route('/countries', methods = ['PUT'])
def update_country():
    session = db.getSession(engine)
    id = request.form['key']
    country = session.query(entities.Country).filter(entities.Country.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(country, key, c[key])
    session.add(country)
    session.commit()
    return 'Updated Country'

@app.route('/countries', methods = ['DELETE'])
def delete_country():
    id = request.form['key']
    session = db.getSession(engine)
    countries = session.query(entities.Country).filter(entities.Country.id == id)
    for country in countries:
        session.delete(country)
    session.commit()
    return "Deleted Country"

# [ C R U D     C I T I E S]

@app.route('/cities', methods = ['GET'])
def get_cities():
    session = db.getSession(engine)
    dbResponse = session.query(entities.City)
    data = []
    for city in dbResponse:
        data.append(city)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')

@app.route('/cities', methods = ['POST'])
def create_city():
    c =  json.loads(request.form['values'])
    city = entities.City(
        name=c['name'],
        country_id=c['country_id']
    )
    session = db.getSession(engine)
    session.add(city)
    session.commit()
    return 'Created City'

@app.route('/cities', methods = ['PUT'])
def update_city():
    session = db.getSession(engine)
    id = request.form['key']
    city = session.query(entities.City).filter(entities.City.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(city, key, c[key])
    session.add(city)
    session.commit()
    return 'Updated Country'

@app.route('/cities', methods = ['DELETE'])
def delete_city():
    id = request.form['key']
    session = db.getSession(engine)
    cities = session.query(entities.City).filter(entities.City.id == id)
    for city in cities:
        session.delete(city)
    session.commit()
    return "Deleted City"

# [ C R U D     D I S T R I C T S ]

@app.route('/districts', methods = ['GET'])
def get_districts():
    session = db.getSession(engine)
    dbResponse = session.query(entities.District)
    data = []
    for district in dbResponse:
        data.append(district)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')

@app.route('/districts', methods = ['POST'])
def create_district():
    c =  json.loads(request.form['values'])
    district = entities.District(
        name=c['name'],
        city_id=c['city_id']
    )
    session = db.getSession(engine)
    session.add(district)
    session.commit()
    return 'Created District'

@app.route('/districts', methods = ['PUT'])
def update_district():
    session = db.getSession(engine)
    id = request.form['key']
    district = session.query(entities.District).filter(entities.District.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(district, key, c[key])
    session.add(district)
    session.commit()
    return 'Updated District'

@app.route('/districts', methods = ['DELETE'])
def delete_district():
    id = request.form['key']
    session = db.getSession(engine)
    districts = session.query(entities.District).filter(entities.District.id == id)
    for district in districts:
        session.delete(district)
    session.commit()
    return "Deleted District"

# [ C R U D     P O S T S ]

@app.route('/posts', methods = ['GET'])
def get_posts():
    session = db.getSession(engine)
    dbResponse = session.query(entities.Post)
    data = []
    for post in dbResponse:
        data.append(post)
    return Response(json.dumps(data, cls=connector.AlchemyEncoder), mimetype='application/json')

@app.route('/posts', methods = ['POST'])
def create_post():
    c =  json.loads(request.form['values'])
    post = entities.Post(
        category_id=c['category_id'],
        district_id=c['district_id'],
        title=c['title'],
        content=c['content']
    )
    session = db.getSession(engine)
    session.add(post)
    session.commit()
    return 'Created Post'

@app.route('/posts', methods = ['PUT'])
def update_post():
    session = db.getSession(engine)
    id = request.form['key']
    post = session.query(entities.Post).filter(entities.Post.id == id).first()
    c =  json.loads(request.form['values'])
    for key in c.keys():
        setattr(post, key, c[key])
    session.add(post)
    session.commit()
    return 'Updated Post'

@app.route('/posts', methods = ['DELETE'])
def delete_posts():
    id = request.form['key']
    session = db.getSession(engine)
    posts = session.query(entities.Post).filter(entities.Post.id == id)
    for post in posts:
        session.delete(post)
    session.commit()
    return "Deleted Post"


if __name__ == '__main__':
    app.secret_key = ".."
    app.run(port=8080, threaded=True, host=('127.0.0.1'))

