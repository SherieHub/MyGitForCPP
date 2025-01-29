class List{
  public:
  
  virtual void addHead(int num) = 0;
  virtual void addTail(int num) = 0;
  virtual int removeHead() = 0;
  virtual int removeTail() = 0;
  virtual int _size() = 0;
  virtual void print() = 0;
};