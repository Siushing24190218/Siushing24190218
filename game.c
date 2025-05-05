name: "WL Commenter"
on:
  - pull_request_target

jobs:
  pr-comment:
    runs-on: ubuntu-latest
    steps:
      - uses: exercism/pr-commenter-action@v1.1.0
        with:
          GITHUB_TOKEN: ${{ secrets.github-token }}
          config-file: ".W L/pr-commenter.yml"