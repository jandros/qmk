FROM qmkfm/base_container

WORKDIR /workspace
COPY . .

ENTRYPOINT ["/bin/bash", "-c", "make"]
CMD ["git-submodules", "all"]
