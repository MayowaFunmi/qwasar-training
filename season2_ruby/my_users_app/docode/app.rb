require 'json'
require 'sinatra'
require_relative 'my_user_model.rb'

set :bind, '0.0.0.0'
set :port, 8080
enable :sessions

get '/' do
    @all_users = User.all()
    erb :index
end

get '/users' do
    status 200
    User.all.map{|x| x.slice("firstname", "lastname", "age", "email")}.to_json
end

post '/users' do
    if params[:firstname] != nil
        add_user = User.create(params)
        new_user = User.find(add_user.id)
        user = {:id => new_user.id, :firstname => new_user.firstname, :lastname => new_user.lastname, :age => new_user.age, :password => new_user.password, :email => new_user.email}.to_json
    else
        auth_user = User.authenticate(params[:password], params[:email])
        if !auth_user[0].empty?
            status 200
            session[:user_id] = auth_user[0]["id"]
        else
            status 401
        end
        auth_user[0].to_json
    end
end

post '/sign_in' do
    auth_user = User.authenticate(params[:password], params[:email])
    if !auth_user.empty?
        status 200
        session[:user_id] = auth_user[0]["id"]
    else
        status 401
    end
    auth_user[0].to_json
end

put '/users' do
    User.update(session[:user_id], 'password', params[:password])
    user = User.find(session[:user_id])
    status 200
    user_info={:firstname=>user.firstname,:lastname=>user.lastname,:age=>user.age,:password=>user.password,:email=>user.email}.to_json
end

delete '/sign_out' do
    session[:user_id] = nil if session[:user_id]
    status 204
end

# uncomment line 61 to delete a user
delete '/users' do
    if !session[:user_id].empty?
        User.destroy(session[:user_id])
    end
    status 200
end
