FROM qmkfm/base_container

WORKDIR /workspace
COPY . .

ENTRYPOINT ["/usr/bin/make"]
CMD ["git-submodules", "all"]
