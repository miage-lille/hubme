import React from "react";

import { make as FetchedDogPictures } from "../src/FetchedDogPictures/FetchedDogPictures.bs.js";

export default {
  title: "Dogs",
  component: FetchedDogPictures
};

export const Dogs = () => <FetchedDogPictures />;

Dogs.story = {
  name: "FetchedDogPictures"
};
