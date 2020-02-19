import React from "react";

import { make as BlinkingGreeting } from "../src/BlinkingGreeting/BlinkingGreeting.bs.js";
import { withKnobs, text } from "@storybook/addon-knobs";

export default {
  title: "Blinking",
  decorators: [withKnobs]
};

export const Blinking = () => (
  <BlinkingGreeting>{text("Blinking text", "Coucou")}</BlinkingGreeting>
);

Blinking.story = {
  name: "Blinking"
};
