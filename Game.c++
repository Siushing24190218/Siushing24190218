name: W L cazre
on:
  pull_request:
    types: [opened, ready_for_review]

jobs:
  label:

    runs-on: ubuntu-latest
    steps:
    - uses: actions/labeler@v2
      with:
        repo-token: "${{ secrets.Siu Shing_TOKEN }}"