class UsersController < ApplicationController
	def index
    	@users = User.all
	end

	def show
		@user = User.find(params[:id])
	end

	def new
		@user = User.new
	end

	def create
		@user = User.new(user_params)

		if @user.save
    		redirect_to @user
  		else
    		render 'new'
  		end
	end

	private
		def user_params
			params.require(:user).permit(:first_name, :last_name, :password, :reason)
		end
end
