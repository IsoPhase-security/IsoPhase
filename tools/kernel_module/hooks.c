#include <linux/module.h>
#include "hooks.h"
#include "sys_hook.h"
#include <linux/sched.h>

#define DEBUG 1
extern struct sys_hook *lkh_sys_hook;

asmlinkage int mkdir_hook(const char *path, int mode)
{
    sys_mkdir_t sys_mkdir;
    
    sys_mkdir = (sys_mkdir_t)sys_hook_get_orig64(lkh_sys_hook, __NR_mkdir);
if(DEBUG)
{
    printk("mkdir is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_mkdir(path, mode);
}

// asmlinkage int open_hook(const char *pathname, int flags)
// {
//     sys_open_t sys_open;
//     sys_open = (sys_open_t)sys_hook_get_orig64(lkh_sys_hook,__NR_open);
//     printk("open is hooked\n");
//     printk("The process id is %d\n", (int) task_pid_nr(current));
//     printk("The process vid is %d\n", (int) task_pid_vnr(current));
//     printk("The process name is %s\n", current->comm);
//     printk("\n\n");

//     return sys_open(pathname,flags);
// } 
asmlinkage int open_hook(const char *pathname, int flags, mode_t mode)
{
    sys_open2_t sys_open;
    sys_open = (sys_open2_t)sys_hook_get_orig64(lkh_sys_hook,__NR_open);
if(DEBUG)
{
    printk("open is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_open(pathname,flags,mode);

}

asmlinkage long execve_hook(const char __user * filename,
				const char __user * const __user * argv,
				const char __user * const __user * envp)
{
    sys_execve_t sys_execve;
    sys_execve = (sys_execve_t)sys_hook_get_orig64(lkh_sys_hook,__NR_execve);
if(DEBUG)
{
    printk("execve is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_execve(filename,argv,envp);
}

asmlinkage int unlink_hook(const char *pathname)
{
    sys_unlink_t sys_unlink;
    sys_unlink = (sys_unlink_t)sys_hook_get_orig64(lkh_sys_hook,__NR_unlink);
if(DEBUG)
{
    printk("unlink is hooked\n");
    printk("The process id is %d\n", (int) task_pid_nr(current));
    printk("The process vid is %d\n", (int) task_pid_vnr(current));
    printk("The process name is %s\n", current->comm);
    printk("\n\n");
}
    return sys_unlink(pathname);
}