## fifo
参照: http://www.ncad.co.jp/~komata/c-kouza12.htm

## unix domain socket
参照:  
- http://qiita.com/nk_yohn3301/items/7aec184e290940052ed2
- http://www.geocities.co.jp/Athlete-Samos/7760/study/unix_socket1.html

```
・domain
AF_INET  インタネット(INET)ドメインの2ホスト間プロセス通信。ARPAインターネットプロトコル(UNIXネットワークソケット)。
AF_UNIX  UNIXドメインの1ホスト内プロセス通信。ファイルシステムソケット。
AF_ISO   ISO標準プロトコル
AF_NS    Xerox Network Systemsプロトコル

・type
SOCK_STREAM  順次双方向バイトストリーム。コネクション型。信頼性が高い。
SOCK_DGRAM   データグラム。コネクションレス型。信頼性が低い。UDPで提供。
SOCK_ROW     直接IPを用いた通信を行なう

・protocol
0            自動設定(AF_INET&SOCK_RAWでIPを直接扱いたい場合も含む)
IPPROTO_TCP  TCP/IP(AF_INET&SOCK_STREAMの場合。0も可。)
IPPROTO_UDP  UDP/IP(AF_INET&SOCK_DGRAMの場合。0も可。)
IPPROTO_RAW  ICMP(pingコマンドなど。AF_INET&SOCK_RAWでICMPソケットを作りたい場合)
```

## HTTPサーバーを立ててみる
目標: HTTPサーバーを立てる

・第一段階
特定の文字がきたら、`html/success.html`、それ以外は、`error.html` を返すようにする。

・第二段階
HTTP を実装する
TODO: TCP通信で送られてくる、文字列をHTTPとしてパースし、解釈して、結果を返す。
- [ ] HTTPパース(難易度10)
- [ ] パースしたものを振り分ける(難易度3)
- [ ] 結果を正しく返す(難易度1)

- [ ] 動かすポートを指定できたらいいかも
- [ ] UDP サーバーとしても動かせたらいいかも

## sockaddr, sockaddr_un, sockaddr_in について
http://www-cms.phys.s.u-tokyo.ac.jp/~naoki/CIPINTRO/NETWORK/struct.html
