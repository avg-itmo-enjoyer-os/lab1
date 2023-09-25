//
// Created by kharl on 16.09.2023.
//

#ifndef XV6_RISCV_KERNEL_DUMP_H
#define XV6_RISCV_KERNEL_DUMP_H

enum dump_ret_codes {
  DUMP_SUCCESS = 0,
  DUMP_INVALID_RIGHTS = -1,
  DUMP_INVALID_PID = -2,
  DUMP_INVALID_REG_NUM = -3,
  DUMP_UNABLE_TO_WRITE_RET_VAL = -4,
};

#endif //XV6_RISCV_KERNEL_DUMP_H
