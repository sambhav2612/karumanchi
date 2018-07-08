'use strict';

var _express = require('express');

var _express2 = _interopRequireDefault(_express);

var _path = require('path');

var _path2 = _interopRequireDefault(_path);

var _bodyParser = require('body-parser');

var _bodyParser2 = _interopRequireDefault(_bodyParser);

var _expressSession = require('express-session');

var _expressSession2 = _interopRequireDefault(_expressSession);

var _cors = require('cors');

var _cors2 = _interopRequireDefault(_cors);

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

var _errorhandler = require('errorhandler');

var _errorhandler2 = _interopRequireDefault(_errorhandler);

var _util = require('util');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

_mongoose2.default.promise = global.Promise;

var isProduction = process.env.NODE_ENV === 'development';

var app = (0, _express2.default)();

app.use((0, _cors2.default)());
app.use(require('morgan')('dev'));
app.use(_bodyParser2.default.urlencoded({
    extended: false
}));
app.use(_bodyParser2.default.json());
app.use(_express2.default.static(_path2.default.join(__dirname, 'public')));
app.use((0, _expressSession2.default)({
    secret: 'karumanchi',
    cookie: {
        maxAge: 60000
    },
    resave: false,
    saveUninitialized: false
}));

if (!isProduction) app.use((0, _errorhandler2.default)());

_mongoose2.default.connect('mongodb://sambhav2612:shambhav2612ds131551.mlab.com:31551/karumanchi');
_mongoose2.default.set('debug', true);

if (!isProduction) {
    app.use(function (err, req, res) {
        res.status(err.status || 500);
        res.json({
            errors: {
                message: err.message,
                error: err
            }
        });
    });
}

app.use(function (err, req, res) {
    res.status(err.status || 500);

    res.json({
        errors: {
            message: err.message,
            error: {}
        }
    });
});

app.listen(8000, function () {
    return console.log('Server running on http://localhost:8000/');
});