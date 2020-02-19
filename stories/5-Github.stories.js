import React from "react";

import { make as Github } from "../src/Github/Github.bs.js";
import { make as GProfile } from "../src/Github/Profile.bs.js";
import { withKnobs, text, number } from "@storybook/addon-knobs";

export default {
  title: "Github Profile",
  decorators: [withKnobs]
};

export const Profile = () => (
  <GProfile
    status={text("Status", "Coding the world")}
    followers={number("Followers (count)", 1000)}
    following={number("Following (count)", 0)}
    name={text("Name", "Eliott Alderson")}
    avatar={text(
      "Avatar URL",
      "https://upload.wikimedia.org/wikipedia/commons/thumb/4/4f/SXSW_2016_-_Rami_Malek_%2825138464364%29_%28cropped_2%29.jpg/260px-SXSW_2016_-_Rami_Malek_%2825138464364%29_%28cropped_2%29.jpg"
    )}
  />
);

// Not working bug with webpack HMR ...need time to investigate but not blocking for the project's needs
export const WithGraphQL = () => (
  <Github token={text("Github Token", "XXX_PUT_YOUR_TOKEN_HERE_XXX")} />
);
