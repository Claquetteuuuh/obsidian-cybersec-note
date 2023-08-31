![[logo-wonderlive-plain-text.svg]]

# Wonderlive dashboard

The user dashboard of the wonderlive project.

## Versions
### Technologies

| **Technologie** | **Version** |
| --------------- | ------- |
| NextJS          | 13.4.7  |
| NodeJS          | 18.13.0 |
### Dependences

| **Dependences**  | **Version** |
| ---------------- | ----------- |
| axios            | ^1.3.4      |
| eslint           | 8.43.0      |
| ethers           | ^5.7.2      |
| framer-motion    | ^10.12.18   |
| prisma           | ^4.16.1     |
| react            | ^18.2.0     |
| react-router-dom | ^6.14.0     |
| typescript       | ^5.1.3      |
| @prisma/client   | ^4.16.2            |
## Quick Start
### Local

- Clone the project using `git clone <HTTP URL>`
- Download the dependencies using `npm i -y`
- Create a `.env` file in the root of the project
	- Create the `DATABASE_URL` variable and place your sqlite DB file location here
	- Create the `RAMP_KEY` variable and place your rampkey value here
	- Create the `WEB3AUTH_CLIENT_ID` variable and place your WEB3AUTH client id value here
- Go to the `/config/chainConfig.ts` file
	- Edit the `rpcTarget` value if you want another rpc
	- Don't forget to change the chainId value according to your `rpcTarget` version
- Finally run `npm run dev` to start the project
- (Optional) run `npx prisma studio` if you want to manage your DB manually
### Vercel

- Go to the `/config/chainConfig.ts` file
	- Edit the `rpcTarget` value if you want another rpc
	- Don't forget to change the chainId value according to your `rpcTarget` version
- Go to the `/prisma/shema.prisma` file
	- set your `provider` (l.9) to `mysql` or `postgresql` instead of `sqlite`
- Deploy on [Vercel](https://vercel.com/), set following environment variables：
	- `DATABASE_URL`, your Mysql or Postgresql DB url
	- `RAMP_KEY`, your rampkey
	- `WEB3AUTH_CLIENT_ID`, your WEB3AUTH client id
- Press the run button

## 