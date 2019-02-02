#thrift --gen c_glib thbdb.thrift
#thrift --gen py ../../src/thbdb.thrift
thrift --gen java -out ./java_test/src/main/java ../../src/thbdb.thrift
