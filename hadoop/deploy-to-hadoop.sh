rm -f build/libs/*.jar
./gradlew jar
docker cp build/libs/PORR-Hadoop-1.0-SNAPSHOT.jar namenode:porr.jar