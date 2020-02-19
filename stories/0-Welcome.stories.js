import React from "react";

import { make as Greeting } from "../src/Greeting/Greeting.bs.js";

export default {
  title: "Welcome",
  component: Greeting
};

export const Welcome = () => <Greeting />;

Welcome.story = {
  name: "Greeting"
};
