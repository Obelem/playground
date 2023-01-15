#!/usr/bin/python3
''' would contain the definition of the application and views '''
from flask import Flask
from example_blueprint import example_blueprint

app = Flask(__name__)

# commented view function due to usage of blueprint
# @app.route('/')
# def index():
#     return 'example app\n'

app.register_blueprint(example_blueprint)
