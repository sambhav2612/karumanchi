Rails.application.routes.draw do
  get 'karumanchi/index'
  get 'welcome/index'
  resources :users
  root 'welcome#index'
end
