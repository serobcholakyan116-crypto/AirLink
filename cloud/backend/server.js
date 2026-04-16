const express = require("express");
const app = express();

app.use(express.json());

let state = {};

app.get("/api/state", (req, res) => {
    res.json(state);
});

app.post("/api/state", (req, res) => {
    state = req.body;
    res.sendStatus(200);
});

app.listen(3000, () => {
    console.log("Backend running on port 3000");
});
