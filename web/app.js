import express from 'express';
import path from 'path';
import bodyParser from 'body-parser';
import session from 'express-session';
import cors from 'cors';
import mongoose from 'mongoose';
import errorHandler from 'errorhandler';
import {
    debug
} from 'util';

mongoose.promise = global.Promise;

const isProduction = process.env.NODE_ENV === 'development';

const app = express();

app.use(cors());
app.use(require('morgan')('dev'));
app.use(bodyParser.urlencoded({
    extended: false
}));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')));
app.use(session({
    secret: 'karumanchi',
    cookie: {
        maxAge: 60000
    },
    resave: false,
    saveUninitialized: false
}));

if (!isProduction)
    app.use(errorHandler());

mongoose.connect(`mongodb://${sambhav2612}:${shambhav2612}@ds131551.mlab.com:31551/karumanchi`);
mongoose.set('debug', true);

import './models/users.js';
import './config/passport.js';

if (!isProduction) {
    app.use((err, req, res) => {
        res.status(err.status || 500);
        res.json({
            errors: {
                message: err.message,
                error: err,
            },
        });
    });
}

app.use((err, req, res) => {
    res.status(err.status || 500);
    res.json({
        errors: {
            message: err.message,
            error: {},
        },
    });
});

app.listen(8000, () => console.log('Server running on http://localhost:8000/'));
