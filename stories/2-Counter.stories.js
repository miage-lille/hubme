import React from "react";

import { make as ReducerFromReactJSDocs } from "../src/ReducerFromReactJSDocs/ReducerFromReactJSDocs.bs.js";

export default {
  title: "Counter",
  component: ReducerFromReactJSDocs
};

export const Counter = () => <ReducerFromReactJSDocs />;

Counter.story = {
  name: "Counter"
};
