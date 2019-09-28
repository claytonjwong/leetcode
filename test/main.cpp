class String {
public:
    explicit String (int n); //allocate n bytes
    explicit String(const char *p); // initialize object with string p
};

int main() {
    String ok{"s"};
    String not_ok{'s'};
    return 0;
}