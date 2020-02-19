module.exports = {
  stories: ["../stories/**/*.stories.js"],
  addons: ["@storybook/addon-knobs/register"],
  webpackFinal: async config => {
    // do mutation to the config
    config.module.rules[0].use[0].options.sourceType = "unambiguous";

    return config;
  }
};
