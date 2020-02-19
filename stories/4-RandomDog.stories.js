import React from "react";

import { make as FetchRandomDog } from "../src/FetchRandomDog/FetchRandomDog.bs.js";

export default {
  title: "Dogs",
  component: FetchRandomDog
};

export const RandomDog = () => <FetchRandomDog />;

RandomDog.story = {
  name: "FetchRandomDog"
};
