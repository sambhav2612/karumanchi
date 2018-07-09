require 'test_helper'

class KarumanchiControllerTest < ActionDispatch::IntegrationTest
  test "should get index" do
    get karumanchi_index_url
    assert_response :success
  end

end
