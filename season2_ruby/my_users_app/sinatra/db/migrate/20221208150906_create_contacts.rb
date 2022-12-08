class CreateContacts < ActiveRecord::Migration[7.0]
  def change
    create_table :contacts do |t|
      t.string :first_name
      t.string :last_name
      t.string :email, null: false
    end
  end
end


# created by command = 
# rake db:create_migration NAME=create_contacts
# rake db:create              # Creates the database from DATABASE_URL or config/database.yml for the current RAIL...
# rake db:create_migration    # Create a migration (parameters: NAME, VERSION)
# rake db:drop                # Drops the database from DATABASE_URL or config/database.yml for the current RAILS_...
# rake db:encryption:init     # Generate a set of keys for configuring Active Record encryption in a given environ...
# rake db:environment:set     # Set the environment value for the database
# rake db:fixtures:load       # Loads fixtures into the current environment's database
# rake db:migrate             # Migrate the database (options: VERSION=x, VERBOSE=false, SCOPE=blog)
# rake db:migrate:down        # Runs the "down" for a given migration VERSION
# rake db:migrate:redo        # Rolls back the database one migration and re-migrates up (options: STEP=x, VERSION=x)
# rake db:migrate:status      # Display status of migrations
# rake db:migrate:up          # Runs the "up" for a given migration VERSION
# rake db:prepare             # Runs setup if database does not exist, or runs migrations if it does
# rake db:reset               # Drops and recreates all databases from their schema for the current environment an...
# rake db:rollback            # Rolls the schema back to the previous version (specify steps w/ STEP=n)
# rake db:schema:cache:clear  # Clears a db/schema_cache.yml file
# rake db:schema:cache:dump   # Creates a db/schema_cache.yml file
# rake db:schema:dump         # Creates a database schema file (either db/schema.rb or db/structure.sql, depending...
# rake db:schema:load         # Loads a database schema file (either db/schema.rb or db/structure.sql, depending o...
# rake db:seed                # Loads the seed data from db/seeds.rb
# rake db:seed:replant        # Truncates tables of each database for current environment and loads the seeds
# rake db:setup               # Creates all databases, loads all schemas, and initializes with the seed data (use ...
# rake db:version             # Retrieves the current schema version number