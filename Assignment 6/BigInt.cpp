#include "BigInt.h"

// ------------------------------------------------------------
BigInt::BigInt() : BigInt("0000000000") {}

// ------------------------------------------------------------
BigInt::BigInt(const string &num) {
    myVec = make_ptr<int[]>(mySize);
    for (int i = 0; i < mySize; ++i) {
        myVec[i] = num[i] - '0';
    }
}

// ------------------------------------------------------------
BigInt::~BigInt() {
    //delete[] myVec.get();
}

// ------------------------------------------------------------
BigInt::BigInt(const BigInt &bi)
        : myVec(new int[bi.mySize]) {
    cout << "==> Copy c'tor\n";
    copy(bi.myVec.get(), bi.myVec.get() + mySize, myVec.get()); // std::copy
}

// ------------------------------------------------------------
BigInt &BigInt::operator=(const BigInt &bi) {
    cout << "==> Copy assignment\n";
    if (this != &bi) {
        int *p = new int[bi.mySize];
        copy(bi.myVec.get(), bi.myVec.get() + mySize, p);
        //delete[] myVec.get();
        myVec.reset(p);
    }

    return *this;
}

// ------------------------------------------------------------
BigInt::BigInt(BigInt &&bi)
        : myVec(bi.myVec.get()) {
    cout << "==> Move c'tor\n";
    bi.myVec = nullptr;
}

// ------------------------------------------------------------
BigInt &BigInt::operator=(BigInt &&bi) {
    cout << "==> Move assignment\n";
    //delete[] myVec.get();
    myVec.reset(bi.myVec.get());
    bi.myVec = nullptr;

    return *this;
}

// ------------------------------------------------------------
bool BigInt::operator==(const BigInt &bi) const {
    for (int i = 0; i < bi.mySize; ++i) {
        if (myVec[i] != bi.myVec[i]) {
            return false;
        }
    }

    return true;
}

// ------------------------------------------------------------
bool BigInt::operator!=(const BigInt &bi) const {
    // Make use of the already implemented '==' operator
    return !(*this == bi);
}

// ------------------------------------------------------------
bool BigInt::operator<(const BigInt &bi) const {
    for (int i = 0; i < mySize; ++i) {
        int diff = myVec[i] - bi.myVec[i];
        if (diff < 0) {
            return true;
        } else if (diff > 0) {
            return false;
        }
    }

    return false;
}

// ------------------------------------------------------------
BigInt BigInt::operator+(const BigInt &bi) const {
    // Perform the addition in columns from LSB to MSB
    int result[mySize];
    int carry = 0;
    for (int i = mySize - 1; i >= 0; --i) {
        int add = myVec[i] + bi.myVec[i] + carry;
        result[i] = add % 10;
        carry = add / 10;
    }

    // At the end of the computation, if 'carry' is non-zero,
    // it means we need another digit to store the result
    // (aka, overflow)
    if (carry > 0) {
        overflow_error("overflow");
    }

    // Convert vector back to a string
    ostringstream buf;
    for (auto i: result) {
        buf << i;
    }

    // And return a new BigInt based on the string
    return BigInt(buf.str());
}


// ------------------------------------------------------------
int main(int ac, char *av[]) {
    BigInt i1("9999999998");
    BigInt i2("0000000001");
    BigInt i3("0000000001");
    BigInt i4;

    cout << "i1: " << i1 << endl
         << "i2: " << i2 << endl
         << "i3: " << i3 << endl
         << "i4: " << i4 << endl
         << endl;

    try {
        cout << "Copy c'tor test (i5 = i3):" << endl;
        BigInt i5 = i3;
        cout << "i5=" << i5 << endl;
        cout << "Copy assignment test (i4 = i3):" << endl;
        i4 = i3;
        cout << "i4=" << i4 << endl << endl;

        cout << "Move c'tor test (i6 = std::move(BigInt(\"0000000015\"))):" << endl;
        BigInt i6 = std::move(BigInt("0000000015"));
        cout << "i6=" << i6 << endl;
        cout << "Move assignment test (i5 = BigInt(\"0000000010\"):" << endl;
        i5 = BigInt("0000000010");
        cout << "i5=" << i5 << endl << endl;

        cout << "Equality operators:" << endl
             << "i1 == i2: expected=0: " << (i1 == i2) << endl
             << "i1 != i3: expected=1: " << (i1 != i3) << endl
             << "i2 == i3: expected=1: " << (i2 == i3) << endl
             << endl;

        cout << "Less-than operator:" << endl
             << "i2 < i1: expected=1: " << (i2 < i1) << endl
             << "i1 < i3: expected=0: " << (i1 < i3) << endl
             << "i2 < i3: expected=0: " << (i2 < i3) << endl
             << endl;

        cout << "Addition operator:" << endl
             << "i1 + i2: expected=9999999999: " << (i1 + i2) << endl
             << "i2 + i3 + i4: expected=0000000003: " << (i2 + i3 + i4) << endl;
        cout << "i1 + i2 + i3: expected=overflow: " << (i1 + i3 + i3) << endl
             << endl;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}