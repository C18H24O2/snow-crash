/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:50:32 by kiroussa          #+#    #+#             */
/*   Updated: 2025/03/21 12:28:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Micro-serv practice software

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>

// Simple error wrapper
static inline int w(char* state, int x) {
	if (x < 0) {
		perror(state);
		exit(EXIT_FAILURE);
	}
	return x;
}

static inline void setup(char **argv) {
	char *tmpfile = argv[1];
	unlink(tmpfile);
	int fd = w("open", open(tmpfile, O_CREAT | O_RDWR, 0600));
	close(fd);
}

static inline void swap(char **argv) {
	char *tmpfile = argv[1];
	char *tokenfile = argv[2];

	w("unlink", unlink(tmpfile));
	w("symlink", symlink(tokenfile, tmpfile));
}

int	main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <tmp-file> <token-file>\n", argv[0]);
		fprintf(stderr, "Example: %s /tmp/token.txt /home/user/level10/token\n", argv[0]);
		return 0;
	}
	setup(argv);
	int sock = w("socket", socket(AF_INET, SOCK_STREAM, 0));
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6969);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	w("bind", bind(sock, (struct sockaddr*)&addr, sizeof(addr)));
	w("listen", listen(sock, 5));
	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	printf("Listening (%s:%d)...\n", inet_ntoa(addr.sin_addr), addr.sin_port);
	fd_set res;
	FD_ZERO(&res);
	FD_SET(sock, &res);
	int r = w("select", select(sock + 1, &res, NULL, NULL, NULL));
	if (r == 0) { printf("Nothing happened, what?\n"); return 0; }
	printf("Something happened, swapping...\n");
	swap(argv);
	printf("Accepting...\n");
	int client_sock = w("accept", accept(sock, NULL, NULL));
	char buf[65536];
	while (1) {
		bzero(buf, sizeof(buf));
		r = w("recv", recv(client_sock, buf, sizeof(buf), 0));
		if (r == 0) break;
		printf("%s", buf);
	}
	close(sock);
	return 0;
}
