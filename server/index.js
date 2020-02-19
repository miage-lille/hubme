// Server for cutii-desktop browser app
const express = require("express");
const path = require("path");
const fs = require("fs");
const compression = require("compression");
const helmet = require("helmet");

const app = express();
const PORT = process.env.PORT || 3998;
const DIST = path.join(__dirname, "..", "bundleOutput");

app.enable("trust proxy");

app.use(compression());
app.disable("x-powered-by");
app.use(
  helmet.hsts({
    // Must be at least 18 weeks to be approved by Google
    maxAge: 10886400,
    // Must be enabled to be approved by Google
    includeSubDomains: true,
    preload: true
  })
);

app.use(express.static(DIST));

app.get("*", (req, res) =>
  fs.createReadStream(path.join(DIST, "index.html")).pipe(res)
);

app.listen(PORT, () =>
  process.stdout.write(`server started on port ${PORT}\n`)
);

process.on("unhandledRejection", console.error);
