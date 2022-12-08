class Users < ActiveRecord::Migration[7.0]
  def change
    create_table :users do|t|
      t.string :email, null: false
      t.string :username, null: false
      t.string :password
  end
end

# created by command = 
# rake db:create_migration NAME=Users