struct foo {
  int (*bar)(struct foo *this, int a, int b); // 函数指针
};

void baz() {
  struct foo *ptr = get_object();
  ptr->bar(ptr, 3, 4);
  // 等效于C++: ptr->bar(3, 4)
}

int main(){
  baz();
}