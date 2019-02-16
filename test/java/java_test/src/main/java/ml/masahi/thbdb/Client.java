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

		try {
			client.put("a", "a-value");
			client.put("test", "testバリュー");
			client.put("あ", "あ");
		} catch (Exception ee) {
		}

		// Testing "Get Keys"
		Keys resultKeys1 = client.getKeysByPosition(1, 1);
		resultKeys1.key.forEach(System.out::println);
		// if( true ) return;

		result = client.get("a");
		System.out.println(result);

		result = client.get("test");
		System.out.println(result);

		client.put("テスト", "テストーバリュー");

		result = client.get("テスト");
		System.out.println(result);

		// put() 10000 times.
		for (int i = 0; i < 10000; i++) {
			String key = String.format("KEY[%05d]", i);
			String value = String.format("VAL[%05d]", i);
			client.put(key, value);
		}

		result = client.get("KEY[00008]");
		System.out.println("VALUE = " + result);

		Keys resultKeys = client.getKeysByPosition(100, 10);
		resultKeys.key.forEach(System.out::println);

		// put() 10000 times.
		for (int i = 0; i < 10000; i++) {
			String key = String.format("KEY2[%05d]", i);
			String value = String.format("VAL2[%05d]", i);
			client.put(key, value);
		}

		result = client.get("KEY2[00008]");
		System.out.println("VALUE = " + result);

		resultKeys = client.getKeysByPosition(100, 10);
		resultKeys.key.forEach(System.out::println);

		resultKeys = client.getKeysByPosition(500, 10);
		resultKeys.key.forEach(System.out::println);

		transport.close();
	}
}
