#pragma once

#include <linux/syscalls.h>
#include "types.h"

typedef asmlinkage int (*sys_mkdir_t)(const char *, int);
asmlinkage int mkdir_hook(const char *, int);

// typedef asmlinkage int (*sys_open_t)(const char *pathname, int flags);
// asmlinkage int open_hook(const char *pathname, int flags);


typedef asmlinkage int (*sys_open2_t)(const char *pathname, int flags, mode_t mode);
asmlinkage int open_hook(const char *pathname, int flags, mode_t mode);

typedef asmlinkage long (*sys_execve_t)(const char __user * filename, const char __user * const __user * argv, const char __user * const __user * envp);
asmlinkage long execve_hook(const char __user * filename, const char __user * const __user * argv, const char __user * const __user * envp);

typedef asmlinkage int (*sys_unlink_t)(const char *pathname);
asmlinkage int unlink_hook(const char *pathname);