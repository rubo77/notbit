/*
 * Notbit - A Bitmessage client
 * Copyright (C) 2014  Neil Roberts
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NTB_IPC_CLIENT_H
#define NTB_IPC_CLIENT_H

#include <stdbool.h>

#include "ntb-error.h"
#include "ntb-buffer.h"

extern struct ntb_error_domain
ntb_ipc_client_error;

enum ntb_ipc_client_error {
        NTB_IPC_CLIENT_ERROR_INVALID_DATA,
        NTB_IPC_CLIENT_ERROR_INVALID_RESPONSE,
        NTB_IPC_CLIENT_ERROR_COMMAND_FAILED,
        NTB_IPC_CLIENT_ERROR_NO_RESPONSE
};

int
ntb_ipc_client_connect(struct ntb_error **error);

bool
ntb_ipc_client_send_command(int sock,
                            const uint8_t *data,
                            size_t data_length,
                            const int *fds,
                            size_t n_fds,
                            struct ntb_error **error);

bool
ntb_ipc_client_get_response(int sock,
                            struct ntb_buffer *response_buf,
                            struct ntb_error **error,
                            uint32_t request_id);

#endif /* NTB_IPC_CLIENT_H */