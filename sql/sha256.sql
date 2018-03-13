select sha256_crypt('Hello world!', '$5$saltstring');
select sha256_crypt('Hello world!', '$5$rounds=10000$saltstringsaltstring');
select sha256_crypt('This is just a test', '$5$rounds=5000$toolongsaltstring');
select sha256_crypt('a very much longer text to encrypt.  This one even stretches over morethan one line.', '$5$rounds=1400$anotherlongsaltstring');
select sha256_crypt('we have a short salt string but not a short password', '$5$rounds=77777$short');
select sha256_crypt('a short string', '$5$rounds=123456$asaltof16chars..');
select sha256_crypt('the minimum number is still observed', '$5$rounds=10$roundstoolow');
