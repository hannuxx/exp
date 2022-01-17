#!/bin/sh

git checkout master out/index.html
mv out/index.html .
rm -rf out
git status
git rm out
git rm -r out
git status
git add index.html
git commit -m "Publishing new index.html"
git push

