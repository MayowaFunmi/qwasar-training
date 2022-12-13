# Welcome to My Users App

---

## Task

The project has 3 parts:
PART 1

To create a User class that will be an interface to create user, find user, get all users, update a user and delete(destroy) user.

Database used is sqlite3 installed using gem, and the sqlite filename is db.sql

PART 2

To have multiple routes in a controller. Routes use http requests such as get, post, put and delete

PART 3
create a view (html page) that will display the firstname, lastname, age and email of 5 users

## Description

The descriptions for each 3 parts are below:

PART 1

Create a my_user_model.rb file and in it, create a modle class User. Create the database table named "users" and it will have multiple attributes:
firstname as string
lastname as string
age as integer
password as string
email as string

Also create following methods for the user class:

def create(user_info)
It will create a user using the sqlite3 INSERT INTO and ruby's User.new() method. User info will be: firstname, lastname, age, password and email
And it will return a unique ID (a positive integer)

def find(user_id)
It will retrieve the associated user using sqlite3's SELECT \* FROM ..... WHERE id = user_id, and return all information contained in the database.

def all
It will retrieve all users using SELECT \* FROM table, and return a hash of users.

def update(user_id, attribute, value)
Use the UPDATE table SET attribute = value WHERE id = user_id. This will retrieve the associated user, update the attribute send as parameter with the value and return the user hash.

def destroy(user_id)
Use the DELETE FROM table WHERE id=user_id. It will retrieve the associated user and destroy it from your database.

Open the database connection at the start of calling each method and close the connection in each method

PART 2

Create a controller and name it app_conroller.rb. The controller has multiple routes using the User class in part 1. Each route will return a json. The routes are as follows:
GET on /users. This action will return all users (without their passwords).

POST on /users. Receiving firstname, lastname, age, password and email. It will create a user and store in your database and returns the user created (without password).

POST on /sign_in. Receiving email and password. It will add a session containing the user_id in order to be logged in and returns the user created (without password).

PUT on /users. This action require a user to be logged in. It will receive a new password and will update it. It returns the user created (without password).

DELETE on /sign_out. This action require a user to be logged in. It will sign_out the current user. It returns nothing (code 204 in HTTP).

DELETE on /users. This action require a user to be logged in. It will sign_out the current user and it will destroy the current user. It returns nothing (code 204 in HTTP).

PART 3

create a directory called views and in it a filename called index.html. Use the template provided to display the user information in html table on the browser

## Installation

install sinatra and sqlite3 using gem

## Usage

run the following command:
bundle init - will create Gemfile
in the gem file, add the following:
gem 'sinatra'
gem 'sqlite3'
run bundle install

### The Core Team

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
