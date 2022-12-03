class Vehicle

    def initialize(id, color, name)
        @veh_id = id
        @veh_color = color
        @veh_name = name

        # displaying values
        puts "ID is: #@veh_id"
        puts "Color is: #@veh_color"
        puts "Name is: #@veh_name"
        puts "\n"
    end
end

# Creating objects and passing parameters
# to new method
xveh = Vehicle. new("1", "Red", "ABC")
yveh = Vehicle. new("2", "Black", "XYZ")

# inheritance
# Ruby program to demonstrate
# the Inheritance

#!/usr/bin/ruby

# Super class or parent class
class GeeksforGeeks

	# constructor of super class
	def initialize
		
		puts "This is Superclass"
	end
	
	# method of the superclass
	def super_method
		
		puts "Method of superclass"
	end
end

# subclass or derived class
class Sudo_Placement < GeeksforGeeks

	# constructor of deriver class
	def initialize

	puts "This is Subclass"
	end
end

# creating object of superclass
GeeksforGeeks.new

# creating object of subclass
sub_obj = Sudo_Placement.new

# calling the method of super
# class using sub class object
sub_obj.super_method
