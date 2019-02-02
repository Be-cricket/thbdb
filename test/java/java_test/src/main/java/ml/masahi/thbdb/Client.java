package ml.masahi.thbdb;

import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;
import ml.masahi.thbdb.gen_java.*;

public class Client {
    
    public static void main(String[] args) throws Exception {
	TTransport transport = new TSocket("localhost", 9090);
	TProtocol protocol = new TBinaryProtocol(transport);
	Basic.Client client = new Basic.Client(protocol);
	transport.open();
	String result = client.hello("Amedama");
	System.out.println(result);

	result = client.hello("あめだま");
	System.out.println(result);


	client.put( "a" , "a-value" );
    client.put( "test" , "testバリュー" );
   	client.put( "あ" , "あ" );
	
	result = client.get( "a" );
	System.out.println(result);

	result = client.get( "test" );
	System.out.println(result);

	client.put( "テスト", "テストーバリュー" );
	

	result = client.get( "テスト" );
	System.out.println(result);

    
	transport.close();
    }
}
