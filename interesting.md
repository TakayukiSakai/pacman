
## LoveField
https://github.com/google/lovefield

ブラウザで動くSQLライクな構文が実行できるIndexedDBのAPIのラッパー/ブラウザで動くデータベース的なもの。
このエンジンのバックエンドは、IndexedDB( https://developer.mozilla.org/ja/docs/IndexedDB )で、ブラウザが提供するストレージAPI。
まだ実験的なブラウザの機能っぽい。

## FIFO, パイプ, Unix domain socket の違い
http://unix.stackexchange.com/questions/75904/are-fifo-pipe-unix-domain-socket-the-same-thing-in-linux-kernel

- FIFO: とても低いレイヤーの概念。FIFOでは、おそらく一方通行のやりとりしかできない。
- Anonymous Pipe: パイプとFIFOは似ていて、違いはパイプは、ファイルシステム上にファイルとして存在しない。なので、openとかできない。
- Socket: ソケットなら複数のコネクションが張れるので、同時にやりとりができるっぽい
