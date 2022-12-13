require 'sqlite3'

class User
    attr_accessor :id, :firstname, :lastname, :age, :password , :email
    def initialize (id=0, firstname, lastname, age, password , email)
        @id=id
        @firstname=firstname
        @lastname=lastname
        @age=age 
        @password=password 
        @email=email
    end

    def self.db_conn()
        begin
            @db = SQLite3::Database.open 'db.sql'
            @db = SQLite3::Database.new 'db.sql' if !@db
            @db.results_as_hash = true
            @db.execute "CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY, firstname STRING, lastname STRING, age INTEGER, password STRING, email STRING)"
            return @db
        rescue SQLite3::Exception => e
            p "Error Ocurred: "
            p e
        end
    end 

    def self.create(user_info)
        @db = self.db_conn
        @db.execute "INSERT INTO users(firstname, lastname, age, password, email) VALUES(?,?,?,?,?)", user_info[:firstname], user_info[:lastname], user_info[:age], user_info[:password], user_info[:email]
        new_user=User.new(user_info[:firstname], user_info[:lastname], user_info[:age], '', user_info[:email])
        new_user.id = @db.last_insert_row_id
        @db.close
        return new_user
    end 

    def self.find(user_id)
        @db = self.db_conn
        find_user = @db.execute "SELECT * FROM users WHERE id = ?", user_id
        user=User.new(find_user[0]["id"], find_user[0]["firstname"], find_user[0]["lastname"], find_user[0]["age"], find_user[0]["password"], find_user[0]["email"])
        @db.close
        return user
    end
     
    def self.all()
        @db = self.db_conn()
        all_users = @db.execute "SELECT * FROM users"
        @db.close
        return all_users
    end 

    def self.update(user_id, attribute, value)
        @db = self.db_conn
        @db.execute "UPDATE users SET #{attribute} = ? WHERE id = ? ", value, user_id
        user_update = @db.execute "SELECT * FROM users where id = ? ", user_id
        @db.close
        return user_update
    end

    def self.destroy(email)
        @db=self.db_conn()
        delete_user=@db.execute "DELETE FROM users WHERE email=#{email}"
        @db.close
        return User.all 
    end 

    def self.authenticate(password, email)
        @db = self.db_conn
        auth_user = @db.execute "SELECT * FROM users WHERE email = ? AND password = ?", email, password
        @db.close
        return User.all 
    end
end 
