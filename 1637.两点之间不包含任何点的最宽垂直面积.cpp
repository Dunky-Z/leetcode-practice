/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

// @lc code=start
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int max_width = 0;
        sort(points.begin(), points.end());
        for(int i = 1; i < points.size(); ++i)
        {
            max_width = max(points[i][0] - points[i-1][0], max_width);
        }
        return max_width;

    }
};
// @lc code=end


 #include <sbi/fw_dynamic.h>
 
-#include "fw_base.S"
+// Use macros to define addresses and offsets
+#define FW_DYNAMIC_INFO_MAGIC_VALUE 0x1548FDBB
+#define FW_DYNAMIC_INFO_VERSION_MAX 0x2
+#define FW_DYNAMIC_INFO_VERSION_2   0x2
+#define FW_DYNAMIC_INFO_MAGIC_OFFSET 0x0
+#define FW_DYNAMIC_INFO_VERSION_OFFSET 0x4
+#define FW_DYNAMIC_INFO_BOOT_HART_OFFSET 0x18
+#define FW_DYNAMIC_INFO_NEXT_ADDR_OFFSET 0x8
+#define FW_DYNAMIC_INFO_NEXT_MODE_OFFSET 0xC
+#define FW_DYNAMIC_INFO_OPTIONS_OFFSET 0x10
 
+// Define the structure of dynamic_info for easier maintenance
+struct dynamic_info {
+    unsigned long magic;
+    unsigned long version;
+    unsigned long next_addr;
+    unsigned long next_mode;
+    unsigned long options;
+    unsigned long boot_hart;
+};
+
+// Declare a variable of structure dynamic_info with initial values
+.section .dynamic, "aw", %progbits
+	.align 3
+_dynamic_info:
+	.word	FW_DYNAMIC_INFO_MAGIC_VALUE
+	.word	FW_DYNAMIC_INFO_VERSION_2 // version = 2
+	.riscv_ptr	0 // next_address = NULL
+	.word	PRV_S // next_mode = PRV_S
+	.riscv_ptr	0 // options = NULL
+	.word	-1 // boot_hart_id = -1
 
 .section .entry, "ax", %progbits
 .align 3
-_bad_dynamic_info:
+wfi
+j	_bad_dynamic_info
 
 .section .entry, "ax", %progbits
 .align 3
+_global fw_boot_hart
 /*
  * This function is called very early even before
  * fw_save_info() is called.
@@ -29,21 +57,43 @@
 */
fw_boot_hart:
 
+	// Load dynamic info structure into register a2
+	lla	a2, _dynamic_info
+	
     /* Sanity checks */
-	li	a1, FW_DYNAMIC_INFO_MAGIC_VALUE
-	REG_L	a0, FW_DYNAMIC_INFO_MAGIC_OFFSET(a2)
-	bne	a0, a1, _bad_dynamic_info
-	li	a1, FW_DYNAMIC_INFO_VERSION_MAX
-	REG_L	a0, FW_DYNAMIC_INFO_VERSION_OFFSET(a2)
-	bgt	a0, a1, _bad_dynamic_info
+	li	a1, FW_DYNAMIC_INFO_MAGIC_VALUE // magic = 0x1548FDBB
+	lw	a0, offsetof(struct dynamic_info, magic)(a2) // load magic value into register a0
+	bne	a0, a1, _bad_dynamic_info // if magic is not equal to 0x1548FDBB, branch to _bad_dynamic_info
 
+	li	a1, FW_DYNAMIC_INFO_VERSION_MAX
+	lw	a0, offsetof(struct dynamic_info, version)(a2) // load version value into register a0
+	bgt	a0, a1, _bad_dynamic_info
 
     /* Read boot HART id */
-	li	a1, FW_DYNAMIC_INFO_VERSION_2
-	blt	a0, a1, 2f
-	REG_L	a0, FW_DYNAMIC_INFO_BOOT_HART_OFFSET(a2)
-	ret
+	blt	a0, FW_DYNAMIC_INFO_VERSION_2, 2f
+	lw	a0, offsetof(struct dynamic_info, boot_hart)(a2) // load boot hart id into register a0
+	ret
 2:	li	a0, -1
     ret
 
 .section .entry, "ax", %progbits
 .align 3
+_global fw_save_info
 /*
@@ -66,19 +116,38 @@
  */ 
 fw_save_info:
 
+	// Load dynamic info structure into register a2
+	lla	a2, _dynamic_info
+	
     /* Save next arg1 in 'a1' */
     lla	a4, _dynamic_next_arg1
-	REG_S	a1, (a4)
+	sw	a1, offsetof(struct dynamic_info, next_addr)(a2)
 
     /* Save version == 0x1 fields */
-	lla	a4, _dynamic_next_addr
-	REG_L	a3, FW_DYNAMIC_INFO_NEXT_ADDR_OFFSET(a2)
-	REG_S	a3, (a4)
-	lla	a4, _dynamic_next_mode
-	REG_L	a3, FW_DYNAMIC_INFO_NEXT_MODE_OFFSET(a2)
-	REG_S	a3, (a4)
-	lla	a4, _dynamic_options
-	REG_L	a3, FW_DYNAMIC_INFO_OPTIONS_OFFSET(a2)
-	REG_S	a3, (a4)
+	sw	a3, offsetof(struct dynamic_info, next_addr)(a2) // save next_address field into dynamic info structure
+	sw	a3, offsetof(struct dynamic_info, next_mode)(a2) // save next_mode field into dynamic info structure
+	sw	a3, offsetof(struct dynamic_info, options)(a2) // save options field into dynamic info structure
 
     /* Save version == 0x2 fields */
-	li	a4, FW_DYNAMIC_INFO_VERSION_2
-	REG_L	a3, FW_DYNAMIC_INFO_VERSION_OFFSET(a2)
-	blt	a3, a4, 2f
-	lla	a4, _dynamic_boot_hart
-	REG_L	a3, FW_DYNAMIC_INFO_BOOT_HART_OFFSET(a2)
-	REG_S	a3, (a4)
+	lw	a0, offsetof(struct dynamic_info, version)(a2) // load version value into register a0
+	bge	a0, FW_DYNAMIC_INFO_VERSION_2, 1f
+	// Don't do anything for version == 1
+	jr	ra
+1:
+	lw	a3, offsetof(struct dynamic_info, boot_hart)(a2) // load boot hart id into register a3
+	sw	a3, offsetof(struct dynamic_info, boot_hart)(a2) // save boot hart id into dynamic info structure
+2:	ret
 
 .section .entry, "ax", %progbits
 .align 3
+_global fw_next_arg1
@@ -93,11 +162,14 @@
 };
 
 .section .entry, "ax", %progbits
-.align 3
-_dynamic_next_arg1:
-RISCV_PTR 0x0
+.align 4
+_global fw_next_addr
+fw_next_addr:
+    lla a0, _dynamic_info
+    lw  a0, offsetof(struct dynamic_info, next_addr)(a0)
+    ret
 
 .section .entry, "ax", %progbits
-.align 3
+_global fw_next_mode
+fw_next_mode:
+    lla a0, _dynamic_info
+    lw  a0, offsetof(struct dynamic_info, next_mode)(a0)
     ret

.section .entry, "ax", %progbits
-.align 3
_dynamic_next_mode:
-RISCV_PTR PRV_S
+.align 4
+_global fw_options
+fw_options:
+    lla a0, _dynamic_info
+    lw  a0, offsetof(struct dynamic_info, options)(a0)
+    ret

.section .entry, "ax", %progbits
-.align 3
_dynamic_options:
-RISCV_PTR 0x0
+.align 4
+_global fw_next_arg1
+fw_next_arg1:
+    lla a0, _dynamic_info
+    lw  a0, offsetof(struct dynamic_info, next_addr)(a0)
+    ret

.section .entry, "ax", %progbits
-.align 3
_dynamic_next_addr:
-RISCV_PTR 0x0
+.align 4
+_global fw_bad_dynamic_info
+fw_bad_dynamic_info:
+    wfi
+    j _bad_dynamic_info 
