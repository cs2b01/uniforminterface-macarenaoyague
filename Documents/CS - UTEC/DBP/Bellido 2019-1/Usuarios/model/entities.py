from sqlalchemy import Column, Integer, String, Sequence, DateTime, ForeignKey
from sqlalchemy.orm import relationship
from database import connector

class Usuarios(connector.Manager.Base):
    __tablename__ = 'usuarios'
    id = Column(Integer, Sequence('usuarios_id_seq'), primary_key=True)
    codigo = Column(String(10))
    nombre = Column(String(30))
    apellido = Column(String(30))
    password = Column(String(15))
