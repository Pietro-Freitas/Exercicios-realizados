int n; cin >> n;
    if (n == 4) cout << "true" << endl;
    else cout << ((n & 4) == 0 ? "true" : "false") << endl;