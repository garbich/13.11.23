#include <iostream>

using namespace std;

class Document {

	string text = "";
public:
	Document() {}
	Document(string _text) : text(_text) {}

	void readDocument() {
		cout << "Text in document: " << text << endl;
	}

	void writeDocument() {
		cout << "input text" << endl;
		cin >> text;
		cout << "text was wrote" << endl;
	}
};

class DocumentAccess {

public:
	virtual void readDocument() = 0;

	virtual void writeDocument() = 0;

};

class RealDocumentAccess : public DocumentAccess {
	Document* document;
public:

	RealDocumentAccess(Document* document_) {
		document = document_;
	}

	void readDocument() override {
		document->readDocument();
		cout << "you read document" << endl;
	}

	void writeDocument() override {
		document->writeDocument();
		cout << "you wrote in document" << endl;
	}

};

class ProxyDocumentAccess : public DocumentAccess {

	Document* document;

public:

	ProxyDocumentAccess(Document* document_) {
		document = document_;
	}

	void readDocument() override {
		string password;
		cout << "input password" << endl;
		cin >> password;
		if (password == "123") {
			document->readDocument();
			cout << "you read document" << endl;
			return;
		}
		cout << "password incorrect" << endl;
	}

	void writeDocument() override {
		string password;
		cout << "input password" << endl;
		cin >> password;
		if (password == "123") {
			document->writeDocument();
			cout << "you wrote in document" << endl;
			return;
		}
		cout << "password incorrect" << endl;
	}
};

int main()
{

	Document* document = new Document();


	RealDocumentAccess* realDocument = new RealDocumentAccess(document);

	ProxyDocumentAccess* proxyDocument = new ProxyDocumentAccess(document);

	realDocument->writeDocument();
	realDocument->readDocument();

	proxyDocument->writeDocument();
	proxyDocument->readDocument();

}