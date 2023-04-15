docker build -t local/panduza-sdk-toolbox:latest .

docker run -v $PWD:/sdk --rm local/panduza-sdk-toolbox:latest
