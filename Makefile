# create directory
name=""
dir:
	cp -r template ${name}

# commit and push all changes
push-all:
	git add . && git commit -m "commit all changes" && git push origin HEAD