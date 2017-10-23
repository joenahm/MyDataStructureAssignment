struct Data{	//struct for data, change it before you use
	int coe;
	int exp;

	Data(){
		coe = 0;
		exp = 0;
	}

	Data(const Data& newData){
		coe = newData.coe;
		exp = newData.exp;
	}

	Data& operator=(const Data& newData){
		coe = newData.coe;
		exp = newData.exp;

		return *this;
	}
};

struct Node{
	Data value;
	Node* next;
	Node(Data inVal, Node* inNext = NULL):value(inVal),next(inNext){}
	Node(const Node& newNode):value(newNode.value),next(newNode.next){}
	Node& operator=(const Node& newNode){
		value = newNode.value;
		next = newNode.next;	

		return *this;
	}

	Node& getNode(){
		return *this;
	}
};

class LL{
private:
	Node* head;
	int length;

public:
	LL(){
		Data h;	//
		h.coe = 0;//构建头结点标识数据
		h.exp =-1;//

		head = new Node(h); //构建头结点
		length = 0;//
	}
	
	LL(const LL& newLL){
		head = new Node(newLL.head->getNode());
		length = newLL.length;
	}

	LL& operator=(const LL& newLL){
		if( &newLL != this ){
			delete head;
			head = new Node(newLL.head->getNode());
			length = newLL.length;
		}

		return *this;
	}

	~LL(){
		Node* temp = head;
		while( temp->next != NULL ){
			Node* buff = temp->next;
			delete temp;
			temp = buff;
		}
	}

	void insert(Data val){
		Node* current; //准备当前元素指针
		Node** linkp = &head->next; //准备存当前元素地址的指针
		Node* inVal = new Node(val);

		while( (current=*linkp) != NULL && current->value.exp < inVal->value.exp ) //循环链表，直到当前元素大于要插入元素
			linkp = &current->next;

		*linkp = inVal; //前一个元素的指针域赋值为新节点的地址
		inVal->next = current; //新节点的指针域赋值为当前元素的地址

		length++;
	}

	int size(){
		return length;
	}

	bool remove(Node* key){
		bool flag = false; //是否找到标记
		Node* temp = head; //准备链表遍历起点

		while( temp->next != NULL ){ //链表遍历
			if( temp->next == key ){ //一旦找到要删除的节点，更改标记，跳出循环
				flag = true; //
				break; //
			}

			temp = temp->next;
		}

		if( flag == true ){
			temp->next = key->next; //从链表中剔除要删除的节点
			delete key; //释放key的内存
			length--; //

			return true;
		}else{
			cerr << "WARNING(LL::remove()):failed to remove key from LinkedList !" << endl;

			return false;
		}

	}

	Node* getHead(){
		return head;
	}

	void traverse(){
		Node* temp = head->next;

		while( temp != NULL ){
			cout << "coe : " << temp->value.coe << ", exp : " << temp->value.exp << endl;

			temp = temp->next;
		}
	}
};
