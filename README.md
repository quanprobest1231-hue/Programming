# Programming
## Tutorial Link:
- Visual Studio Code: https://vscode.download.prss.microsoft.com/dbazure/download/stable/994fd12f8d3a5aa16f17d42c041e5809167e845a/VSCodeUserSetup-x64-1.107.1.exe
    - Extension VS Code: 
        - Code Runner
        - GitLens
        - One Dark Pro
        - vscode-icons
        - C/C++
        - Competitive Programming Helper (cph)
        - GitHub Copilot Chat
- msys2: https://code.visualstudio.com/docs/cpp/config-mingw
- MobaXterm: https://download.mobatek.net/2542025111600034/MobaXterm_Portable_v25.4.zip
- VmWare: https://dn721608.ca.archive.org/0/items/vmware-workstation-pro-17.5.2/VMware-workstation-full-17.5.2-23775571.exe
- Ubuntu: https://releases.ubuntu.com/16.04/ubuntu-16.04.7-desktop-amd64.iso
- How to setting VmWare: https://www.youtube.com/watch?v=MDUHaNq1i_A
- Git bash: https://git-scm.com/install/windows
- TortoiseGit: https://download.tortoisegit.org/tgit/2.18.0.0/TortoiseGit-2.18.0.1-64bit.msi

## Connect VMware Ubuntu from MobaXterm

1. Start the Ubuntu VM in VMware and set its network adapter to **NAT** or **Bridged**.
2. In Ubuntu, install and start SSH:
   ```bash
   sudo apt update
   sudo apt install -y openssh-server
   sudo systemctl enable --now ssh
   ```
3. Get the VM IP address:
   ```bash
   hostname -I
   ```
4. Open MobaXterm, select **Session** > **SSH**, enter the VM IP address, port `22`, and your Ubuntu username. Click **OK**, then enter the password.
5. If it cannot connect, check the VMware network mode and SSH status. If UFW is enabled, allow SSH:
   ```bash
   sudo ufw allow OpenSSH
   ```

## SSH hoạt động như thế nào khi kết nối vào máy ảo VMware?

VMware tạo một **máy tính ảo (VM)** chạy Ubuntu bên trong máy Windows thật (máy **host**). VM có hệ điều hành, tài khoản người dùng và card mạng ảo riêng, nên được cấp một địa chỉ IP riêng trong mạng ảo, ví dụ `192.168.x.x`.

```text
Windows (host) ── mạng ảo VMware ── Ubuntu VM (server SSH)
MobaXterm (SSH client) ── IP của VM :22 ── sshd
```

1. Dịch vụ `sshd` trong Ubuntu lắng nghe kết nối ở cổng `22`.
2. MobaXterm là SSH client: khi nhập IP VM và port `22`, nó gửi yêu cầu mạng từ Windows đến VM.
3. Nếu Windows đi được tới IP đó và cổng `22` đang mở, `sshd` yêu cầu xác thực bằng username/password hoặc SSH key.
4. Sau khi xác thực, SSH tạo một kênh mã hóa để bạn gõ lệnh trên Windows nhưng lệnh được chạy trong Ubuntu VM.

Lệnh `ping <IP-VM>` chỉ là cách nhanh để kiểm tra Windows có liên lạc được tới VM qua mạng hay không. Ping dùng giao thức ICMP, còn SSH dùng TCP cổng `22`; vì vậy ping thành công thường là dấu hiệu tốt, nhưng **không bắt buộc** SSH phải hoạt động. Một firewall có thể chặn ping nhưng vẫn cho phép SSH.

### Chọn chế độ mạng VMware

- **NAT**: VM dùng chung kết nối Internet của Windows qua mạng ảo VMware. Đây thường là lựa chọn đơn giản nhất để Windows kết nối đến VM.
- **Bridged**: VM xuất hiện như một máy riêng trên cùng mạng Wi-Fi/LAN với Windows và nhận IP từ router. Phù hợp khi muốn thiết bị khác trong LAN cũng kết nối vào VM.
- **Host-only**: VM chỉ giao tiếp với Windows và các VM cùng mạng host-only; thường không có Internet.

Trong Ubuntu, dùng `hostname -I` để xem IP. Trên Windows, chạy `ping <IP-VM>` để kiểm tra đường mạng, rồi dùng IP đó trong MobaXterm để kết nối SSH.
