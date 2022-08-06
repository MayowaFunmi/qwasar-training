const bodyParser = require('body-parser')
const express = require('express')
const app = express()
const path = require('path')

app.listen('8080', '0.0.0.0', () => {
    console.log("server is listening on 8080 port");
})


app.use(express.static('public'))
app.use(bodyParser.urlencoded({ extended: true }))
app.engine('html', require('ejs').renderFile)
app.set('view engine', 'html'); // by default, express and ejs looks for views folder
//app.set('views', __dirname)

app.use(express.json())

const songs = [
    'All the Way Home', 'All This and Heaven Too', 'America the Beautiful', 'The Brooklyn Bridge',
    'Call Me', 'Dear Little Boy of Mine', 'Everybody Ought to Be in Love', 'Fly Me to the Moon',
    'A Good MAn is Hard to Find', 'Hello, Dolly', 'I Don"t Stand a Ghost of a Chance with You',
    'I"ve Never Been in Love Before', 'Kiss Me Again', 'Let Us Break Bread Together', 'Maria', 'Noah',
]

app.get('/', (req, res) => {
    const songsDetails = [
        { title: 'All the Way Home', year: 1983, songWriter: ['Teddy Randazzo'] },
        { title: 'All This and Heaven Too', year: 1940, songWriter: ['Eddie DeLange', 'Jimmy Van Heusen'] },
        { title: 'America the Beautiful', year: 1945, songWriter: ['Samuel A. Ward'] },
        { title: 'The Brooklyn Bridge', year: 1946, songWriter: ['Sammy Cahn', 'Jule Styne'] },
        { title: 'Call Me', year: 1966, songWriter: ['Tony Hatch'] },
        { title: 'Dear Little Boy of Mine', year: 1950, songWriter: ['Ernest Ball', 'J. Keirn Brennan'] },
        { title: 'Everybody Ought to Be in Love', year: 1977, songWriter: ['Paul Anka'] },
        { title: 'Fly Me to the Moon', year: 1964, songWriter: ['Bart Howard'] },
        { title: 'A Good MAn is Hard to Find', year: 1951, songWriter: ['Eddie Green'] },
        { title: 'Hello, Dolly', year: 1964, songWriter: ['Jerry Herman'] },
        { title: 'I Don"t Stand a Ghost of a Chance with You', year: 1959, songWriter: ['Victor Young', 'Ned Washington', 'Bing Crosby'] },
        { title: 'I"ve Never Been in Love Before', year: 1963, songWriter: ['Frank Loesser'] },
        { title: 'Kiss Me Again', year: 1944, songWriter: ['Victor Herbert', 'Henry Martyn Blossom'] },
        { title: 'Let Us Break Bread Together', year: 1964, songWriter: ['Roy Ringwald'] },
        { title: 'Maria', year: 1962, songWriter: ['Leonard Bernstein', 'Stephen Sondheim'] },
        { title: 'Noah', year: 1973, songWriter: ['Joe Raposo'] },
        { title: 'One Love', year: 1946, songWriter: ['Leo Robin', 'David Rose'] },
        { title: 'Prisoner of Love', year: 1961, songWriter: ['Russ Columbo', 'Clarence Gaskill', 'Leo Robin'] },
        { title: 'Quiet Nights of Quiet STars ', year: 1967, songWriter: ['Antonio Carlos Jobim', 'Gene Lees'] },
        { title: 'Reaching for the Moon', year: 1965, songWriter: ['Irving Berlin'] },
        { title: 'Same Old Saturday Night', year: 1955, songWriter: ['Sammy Cahn', 'Frank Reardon'] },
        { title: 'There Will Never Be Another You', year: 1961, songWriter: ['Mack Gordon', 'Harry Warren'] },
        { title: 'Until the Real Thing Comes Along', year: 1984, songWriter: ['Sammy Cahn', 'Saul Chaplin', 'L.E. Freeman'] },
        { title: 'The Very Thought of You', year: 1962, songWriter: ['Ray Noble'] },
    ]

    const randomTitle = songsDetails[Math.floor(Math.random() * songsDetails.length)]
    console.log(randomTitle)
    const songTitle = randomTitle.title //JSON.stringify(randomTitle.title)
        //console.log(randomTitle.title)
    res.status(200)
    res.render('app.html', { songTitle })
})

app.get('/birth_date', (req, res) => {
    res.render('birth_date.html', { birth_date: '12 December 1915' })
})

app.get('/birth_city', (req, res) => {
    res.render('birth_city.html', { birth_city: 'Hoboken, New Jersey' })
})

app.get('/wives', (req, res) => {
    res.render('wives.html', { wives: 'Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx' })
})

app.get('/picture', (req, res) => {
    res.render('picture.html')
})

app.get('/public', (req, res) => {
    res.render('public.html')
})

// app.get('/protected', (req, res) => {
//     res.render('protected.html', { login: 'admin', password: 'admin' })
// })

//app.get('/picture', express.static(path.join(__dirname, 'public')))

// basic http authentication

// const auths = (req, res, next) => {
//     const loginDetail = {
//         login: 'admin',
//         password: 'admin'
//     }

//     let authHeader = req.headers.authorization
//     console.log(req.headers)

//     if (!authHeader) {
//         var err = new Error('Not authorized')
//         res.setHeader('WWW-Authenticate', 'Basic realm="Restricted Area')
//         err.status = 401
//         return next(err)
//     }

//     var auth = new Buffer.from(authHeader.split(' ')[1], 'base64').toString().split(':')
//     var user = auth[0]
//     var pass = auth[1]
//     if (user == loginDetail.login && pass == loginDetail.password) {
//         next()
//     } else {
//         var err = new Error('Not authorized')
//         res.setHeader('WWW-Authenticate', 'Basic realm="Restricted Area')
//         err.status = 401
//         return next(err)
//     }
//     next()
// }

// basic http authentication middleware
app.use((req, res, next) => {
    // if 'Authorization' header not present
    if (!req.get('Authorization')) {
        var err = new Error('Unauthorized')
        res.status(401).set('WWW-Authenticate', 'Basic realm="Restricted Area"')
        res.render('unauthorized.html')
        next(err)
    }
    // if 'Authorization' header present
    else {
        // decode the 'Authorization' header based value
        var credentials = Buffer.from(req.get('Authorization').split(' ')[1], 'base64').toString().split(':')
        var username = credentials[0]
        var password = credentials[1]

        //if credebtials are invalid
        if (!(username === 'admin' && password === 'admin')) {
            var err = new Error('Not Authenticated')
            res.status(401).set('WWW-Authenticate', 'Basic')
            next(err)
        }
        res.status(200)
        next()
    }
})
app.get('/protected', (req, res) => {
    res.render('index.html')
})