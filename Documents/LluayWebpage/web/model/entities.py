from sqlalchemy import Column, Integer, String, Sequence, DateTime, ForeignKey
from sqlalchemy.orm import relationship
from database import connector
from datetime import datetime

class Category(connector.Manager.Base):
    __tablename__ ='categories'
    id = Column(Integer, Sequence('user_id_seq'), primary_key=True)
    name = Column(String(30))

class Country(connector.Manager.Base):
    __tablename__ = 'countries'
    id = Column(Integer, Sequence('user_id_seq'), primary_key=True)
    name = Column(String(30))

class City(connector.Manager.Base):
    __tablename__ = 'cities'
    id = Column(Integer, Sequence('user_id_seq'), primary_key=True)
    name = Column(String(30))
    country_id = Column(Integer, ForeignKey('countries.id'))
    country_name = relationship(Country, foreign_keys=[country_id])

class District(connector.Manager.Base):
    __tablename__ = 'districts'
    id = Column(Integer, Sequence('user_id_seq'), primary_key=True)
    name = Column(String(50))
    city_id = Column(Integer, ForeignKey('cities.id'))
    city_name = relationship(City, foreign_keys=[city_id])

class Post(connector.Manager.Base):
    __tablename__ = 'posts'
    id = Column(Integer, Sequence('message_id_seq'), primary_key=True)
    category_id = Column(Integer, ForeignKey('categories.id'))
    category_name = relationship(Category, foreign_keys=[category_id])
    district_id = Column(Integer, ForeignKey('districts.id'))
    district_name = relationship(District, foreign_keys=[district_id])
    title = Column(String(50))
    content = Column(String(500))
    date = Column(default=datetime.now())
