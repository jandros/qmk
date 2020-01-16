FROM qmkfm/base_container

WORKDIR /workspace
COPY . .

ENTRYPOINT [make]
CMD ["git-submodules", "all"]
